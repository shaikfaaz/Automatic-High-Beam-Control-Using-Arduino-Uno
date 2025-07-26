import cv2
import numpy as np
import serial
import time

# Setup Serial communication with Arduino
ser = serial.Serial('COM4', 9600, timeout=1)  # Replace with your port
time.sleep(2)  # Wait for the serial connection to initialize

# Load the target image (template) to detect
template = cv2.imread('target_image1.jpeg', 0)  # Load in grayscale
if template is None:
    print("Error: Template image not found. Please check the file path.")
    exit()

template_width, template_height = template.shape[::-1]

# Set a similarity threshold for template matching
THRESHOLD = 0.6 # Adjust this value (closer to 1 for stricter matching)

# Capture the camera feed
cap = cv2.VideoCapture(0)  # Use 0 for default camera

while True:
    ret, frame = cap.read()
    if not ret:
        print("Error: Unable to capture video.")
        break

    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # Convert the frame to grayscale

    # Apply template matching
    res = cv2.matchTemplate(gray_frame, template, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

    # Debug: Print the maximum value and location
    print(f"Max Value: {max_val}, Max Location: {max_loc}")

    # Only detect the image if the similarity is above the threshold
    if max_val >= THRESHOLD:
        # Get the top-left corner of the matched region
        top_left = max_loc
        bottom_right = (top_left[0] + template_width, top_left[1] + template_height)

        # Draw a rectangle around the detected image
        cv2.rectangle(frame, top_left, bottom_right, (0, 255, 0), 2)

        # Determine if the image is on the left or right side of the camera window
        frame_center = frame.shape[1] // 2
        image_center = top_left[0] + (template_width // 2)

        if image_center < frame_center:
            position = "Left"
            ser.write(b'L')  # Send 'L' to Arduino if the image is on the left
        else:
            position = "Right"
            ser.write(b'R')  # Send 'R' to Arduino if the image is on the right

        # Display the result
        cv2.putText(frame, f"Position: {position}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    else:
        position = "Not Detected"
        cv2.putText(frame, "Position: Not Detected", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    cv2.imshow('Camera Feed', frame)

    # Break loop on 'q' key press
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the capture and close windows
cap.release()
cv2.destroyAllWindows()
ser.close()  # Close serial connection
