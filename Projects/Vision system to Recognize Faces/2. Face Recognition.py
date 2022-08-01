import numpy as np
import cv2 as cv

haar_cascade = cv.CascadeClassifier('haar_face.xml')
people = ['Akshay', 'Allu', 'Hrithik', 'Rashmika']

# features = np.load('features.npy')
# labels = np.load('labels.npy')

face_recognizer = cv.face.LBPHFaceRecognizer_create()
face_recognizer.read('face_trained.yml')

img = cv.imread(r'D:\STUDY MATERIAL\OpenCV\Photos\val\Akshay\download.jpg')

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("Gray", gray)

# Detect the faces in the image
faces_rect = haar_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=3)

for (x,y,g,h) in faces_rect:
    faces_roi = gray[x:x+g, y:y+h]

    label, confidence = face_recognizer.predict(faces_roi)
    print(f'label = {people[label]} with a confidence of {confidence}')

    cv.putText(img, str(people[label]), (20,20), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0,255,0), thickness=2)
    cv.rectangle(img, (x,y), (x+g,y+h), (0,255,0), thickness=2)

cv.imshow("Detected Face", img)
cv.waitKey(0)