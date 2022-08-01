import os
import numpy as np
import cv2 as cv

#One way to add people in the list
# p = []
# for i in os.listdir(r'D:\STUDY MATERIAL\OpenCV\Photos\Faces'):
#     p.append(i)
#
# print(p)

people = ['Akshay', 'Allu', 'Hrithik', 'Rashmika']  #Another way to add people in the list
DIR = r'D:\STUDY MATERIAL\OpenCV\Photos\Faces'
haar_cascade = cv.CascadeClassifier('haar_face.xml')

features = []
labels = []

def create_train():
    for person in people:
        path = os.path.join(DIR, person)
        label = people.index(person)

        for img in os.listdir(path):
            img_path = os.path.join(path, img)

            img_array = cv.imread(img_path)
            gray = cv.cvtColor(img_array, cv.COLOR_BGR2GRAY)

            face_rect = haar_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=4)

            for(x,y,g,h) in face_rect:
                faces_roi = gray[y:y+h, x:x+g]  # roi= region of interest and we are cropping the face  here
                features.append(faces_roi)
                labels.append(label)

create_train()
print('Training done --------------')

features = np.array(features, dtype='object')
labels = np.array(labels)

face_recognizer = cv.face.LBPHFaceRecognizer_create()

#Train the Recognizer on the features list  and the label list
face_recognizer.train(features, labels)

face_recognizer.save('face_trained.yml')
np.save('features.npy', features)
np.save('labels.npy', labels)