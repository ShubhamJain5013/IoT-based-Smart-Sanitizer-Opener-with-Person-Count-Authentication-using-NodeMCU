# IoT-based-Smart-Sanitizer-Opener-with-Person-Count-Authentication-using-NodeMCU
1. The spread of any diseases like recently we heard about CORONA virus is mostly spread in the crowded area like Railway Station, Airport , Bus Stand , Bank , Hotels , Schools,  Colleges etc. So to decrease the chance of spreading the germs through human intervention, or to maintain the hygiene among the people in crowded areas,  I made a “IoT based Smart Sanitizer Opener with Person Count Authentication using NodeMCU” that will check the person who would not use sanitizer and simultaneously send the SMS to the higher authority. 
2.	Things used in this project
2.1.	Hardware components and their cost
2.1.1 NodeMCU (ESP8266)				Rs: 270/-	                
2.1.2 Stepper Motor (Bipolar Stepper Motor)	Rs: 350/-
2.1.3 UltraSonic Sensor (HC-SR04)			Rs: 90/-
2.1.4 IR Sensor					Rs: 40/-
2.1.5 Buzzer						Rs: 15/-
2.1.6 Jumper Wires					Rs: 2/- per piece
2.1.7 L239D Motor Driver IC				Rs: 65/-
2.1.8 9V battery					Rs: 15/-
2.1.9 Breadboard					Rs: 30/-	
	2.2. Sftware apps and online services		
2.2.1 Arduino IDE
		2.2.2 IFTTT (IoT platform)


3. Story
3.1 Introduction
In this project I used two sensors to count one person two times. So that nobody is left to clean their hands with sanitizer or hand wash. This Project reduces the chance of increasing germs in public areas. Let’s take an example of airport entry gate in which passenger enter in the airport line wise. Before the entry gate I placed the sanitizer bottle with ultrasonic sensor to open it automatically when a passenger put their hand in front of sensor and simultaneously the count of each person takes place. After cleaning the hand from sanitizer passenger would asked to enter inside the airport. At the entry gate I placed an IR sensor to count each person. Here counting from both the sensor will checked and if counting of IR sensor is greater than Ultra sonic sensor then buzzer will become activated and an alert message will transfer to higher authority via notification that “Alert! Someone has not clean their hands from Sanitizer”
3.2 Steps of working of project
Step 1 : Switch on the power supply and wait of few seconds so that NodeMCU wifi module will connect to the wifi router (It is necessary because to send notification to mobile phones.).
Step 2: If a person move his/her hand toward ultrasonic sensor then sanitizer bottle will open through stepper motor and also counting of each person is also takes place.
Step 3: Now the same person enter into the gate who uses sanitizer , there an IR sensor is placed to count each person entry.
Step 4: If the counting done by ultrasonic sensor and IR sensor is same then it indicates that the person who enters into the gate uses sanitizer.
Step 5: But if the counting done by both the sensor is not equal i.e. counting done by IR sensor is greater than Ultra sonic sensor , that means someone enters directly without using sanitizer.
Step 6: At that time the Buzzer will ring and a notification will send to the registered mobile number. 
3.3 Advantage
1. Public hygiene will be maintained as germs from one hand to another hand will not spread.
2. This device will work specially in crowded area like railway station, airport, schools, Bus stand etc where chance of spreading germs is more.
3. Counting of each person is also takes place to determine the crowd at a particular area.
4. Message will go to the higher authority so that the security at nearby entry or exit door will not ignore the alert created by device.

