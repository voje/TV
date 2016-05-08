# Webcam user interaction
## Warmup detect running
1. Detect and locate face.
    *using viola-jones face detector
2. Determine whether it's still or moving vertically.
    *determinate baseline dy (changes in y position when user is standing still)
    *listen for dy > baseline changes
