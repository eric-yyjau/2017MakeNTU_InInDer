# USAGE
# python motion_detector.py
# python motion_detector.py --video videos/example_01.mp4

# import the necessary packages
import argparse
import datetime
import imutils
import time
import cv2

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video", help="path to the video file")
ap.add_argument("-a", "--min-area", type=int, default=500, help="minimum area size")
args = vars(ap.parse_args())

# if the video argument is None, then we are reading from webcam
if args.get("video", None) is None:
	camera = cv2.VideoCapture(0)
	time.sleep(0.25)

# otherwise, we are reading from a video file
else:
	camera = cv2.VideoCapture(args["video"])

# initialize the first frame in the video stream
firstFrame = None

# code
frame_count=0

# loop over the frames of the video
while True:
	# grab the current frame and initialize the occupied/unoccupied
	# text
	(grabbed, frame) = camera.read()
	text = "Unoccupied"

	# if the frame could not be grabbed, then we have reached the end
	# of the video
	if not grabbed:
		break
	# code
	'''
	# Smooth to get rid of false positives
	cv.Smooth( color_image, color_image, cv.CV_GAUSSIAN, 19, 0 )

	# resize the frame, convert it to grayscale, and blur it
	frame = imutils.resize(frame, width=500)
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	gray = cv2.GaussianBlur(gray, (21, 21), 0)




	# if the first frame is None, initialize it
	if firstFrame is None:
		firstFrame = gray
		continue

	# compute the absolute difference between the current frame and
	# first frame
	frameDelta = cv2.absdiff(firstFrame, gray)
	thresh = cv2.threshold(frameDelta, 25, 255, cv2.THRESH_BINARY)[1]

	# dilate the thresholded image to fill in holes, then find contours
	# on thresholded image
	thresh = cv2.dilate(thresh, None, iterations=2)
	(_, cnts, _) = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL,
		cv2.CHAIN_APPROX_SIMPLE)
	'''

	camera_image = frame
	frame_count += 1
	frame_t0 = time.time()
	
	# Create an image with interactive feedback:
	display_image = cv.CloneImage( camera_image )
	
	# Create a working "color image" to modify / blur
	color_image = cv.CloneImage( display_image )

	# Smooth to get rid of false positives
	cv.Smooth( color_image, color_image, cv.CV_GAUSSIAN, 19, 0 )
	
	# Use the Running Average as the static background			
	# a = 0.020 leaves artifacts lingering way too long.
	# a = 0.320 works well at 320x240, 15fps.  (1/a is roughly num frames.)
	cv.RunningAvg( color_image, running_average_image, 0.320, None )
	
	# Convert the scale of the moving average.
	cv.ConvertScale( running_average_image, running_average_in_display_color_depth, 1.0, 0.0 )
	
	# Subtract the current frame from the moving average.
	cv.AbsDiff( color_image, running_average_in_display_color_depth, difference )
	
	# Convert the image to greyscale.
	cv.CvtColor( difference, grey_image, cv.CV_RGB2GRAY )

	# Threshold the image to a black and white motion mask:
	cv.Threshold( grey_image, grey_image, 2, 255, cv.CV_THRESH_BINARY )
	# Smooth and threshold again to eliminate "sparkles"
	cv.Smooth( grey_image, grey_image, cv.CV_GAUSSIAN, 19, 0 )
	cv.Threshold( grey_image, grey_image, 240, 255, cv.CV_THRESH_BINARY )
	
	grey_image_as_array = numpy.asarray( cv.GetMat( grey_image ) )
	non_black_coords_array = numpy.where( grey_image_as_array > 3 )
	# Convert from numpy.where()'s two separate lists to one list of (x, y) tuples:
	non_black_coords_array = zip( non_black_coords_array[1], non_black_coords_array[0] )
	
	points = []   # Was using this to hold either pixel coords or polygon coords.
	bounding_box_list = []

	# Now calculate movements using the white pixels as "motion" data
	contour = cv.FindContours( grey_image, mem_storage, cv.CV_RETR_CCOMP, cv.CV_CHAIN_APPROX_SIMPLE )




	# loop over the contours
	for c in cnts:
		# if the contour is too small, ignore it
		if cv2.contourArea(c) < args["min_area"]:
			continue

		# compute the bounding box for the contour, draw it on the frame,
		# and update the text
		(x, y, w, h) = cv2.boundingRect(c)
		cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
		text = "Occupied"

	# draw the text and timestamp on the frame
	cv2.putText(frame, "Room Status: {}".format(text), (10, 20),
		cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)
	cv2.putText(frame, datetime.datetime.now().strftime("%A %d %B %Y %I:%M:%S%p"),
		(10, frame.shape[0] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.35, (0, 0, 255), 1)

	# show the frame and record if the user presses a key
	cv2.imshow("Security Feed", frame)
	cv2.imshow("Thresh", thresh)
	cv2.imshow("Frame Delta", frameDelta)
	key = cv2.waitKey(1) & 0xFF

	# if the `q` key is pressed, break from the lop
	if key == ord("q"):
		break

# cleanup the camera and close any open windows
camera.release()
cv2.destroyAllWindows()