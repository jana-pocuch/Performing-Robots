# Midterm Project
## (1) Initial Brainstorm
For this project I want to build a robot that is not humanoid. I do not want to rely on the humanoid form to imitate human like limb movements and face expression - and want to invent a unique form of expression for the robot, which seems slightly more challenging and experimental. 

The whole semester I've been collecting materials (even though one might easily mistake the collection for trash - I own more bottle caps than I'm willing to admit at this point). And one of the boxes I kept from the NYUAD 10th anniversary D2 cupcakes particularly inspired me. I started sketching initial ideas of how it could move and perform, then tried building it, then I sketched again, built again, sketched again and built again. At first I though I might use the moving servo flower from my previous project, however, when building, I discoverd building a "servo neck" creates a lot more potential for expression. Currently I am in the fourth phase or reiteration, and will probably end up reiterating at least 896 times more. 

<p> <img src="https://user-images.githubusercontent.com/89770035/135754802-44bb9414-7e68-42ff-a538-a9b68385964b.jpg" width="75%" height="75%"> </p>

And this is how the first vs. fourth prototypes looked like in real life:
<p> <img src="https://user-images.githubusercontent.com/89770035/135755194-b1f56536-9980-44e9-bb62-8d2f3774fc9f.JPG" width="30%" height="30%"> <img src="https://user-images.githubusercontent.com/89770035/135755197-cff7ba2f-e708-4ddd-9c1c-8ea69fc0a8b0.JPG" width="30%" height="30%"> </p>

### Expression
My robot will be mainly communicating through the movement of its little head (controlled by a servo), and its face (the Neomatrix). My idea for the sequence is for the robot to be frantically looking around, taking sharp turns and blinking rapidly, which then transitions into "giving up". This transition will be done through slowing down/stopping the motor movement, slowing down the servo turning, and through decrease in the color saturation, brightness and patterns on the Neomatrix. 

### Problems
In terms of building, I experience some of the "classic" troubles we discussed a lot in class: major one of which was tilting of the base that holds the two motors. I want the robot to be as small as possible (because cuteness), so I am only using two wheels. After a few different attempts with sizing the cardboard base and placing the wheels strategically, putting a toilet paper roll in the middle turned out to be the most stable and reliable solution, that allowed the robot to stay relatively small.

<p> <img src="https://user-images.githubusercontent.com/89770035/135755303-40692687-f5e2-49b3-96ee-11859b009405.JPG" width="30%" height="30%"> </p>

Since I am still in the reiterating phase, I am using a lot of adhesive tack for the servo motor to stay in place as well as for holding the box. Glueing them is a committment I am not ready for at this stage just yet. 

I am also using tack for holding the Neopixel in place, but that one, as opposed to the servo and the box, is veeeeery unstable. I still need to figure out a way how to hold the Neopixel in an upright position in the plastic window of the box. But for now, I still need it to be mobile as I am taking things in and out and rewiring, so I have some time to sit on it and think about how to fixate it. 

However, the biggest problem I faced is my lack of coding skills :))) I managed to work on small sequences separately (motors, servos and Neopixel), but the moment I try to paste it all together is where it collapses. I also feel like I am just using sample codes from Arduino and from our class and feel very restricted when it comes to writing code myself (especially for the Neopixel animation). I spent several hours trying to understand how the sample codes work, but I did not manage to understand it to the extent I would be able to put my own visual animation idea into code. So, unfortunatelly, this seems like the biggest obstacle so far, that I will need to spend a lot of time on, just doing endless loops of trial and error. 

## (2) Process
The main continuous challenge throghout this project was to make the three parts work together. For 99% of the whole process, my robot was deconstructed into separate parts, with me constantly uploading code to it in a trial-error manner. So my workspace resembled anything but a robot:

<p> <img src="https://user-images.githubusercontent.com/89770035/137500553-cec0f5df-4e8b-45b3-bc84-cbb03a961d33.JPG" width="30%" height="30%"> </p>

**NeoPixel** 
<p> I spent a lot of time trying to program neopixel sequences myself, but it took me a lot to even understand some of the prebuilt example code, and I could not really bring my vision to life, without using delay. Here are some initial ideas I was sketching: 
<p> <img src="https://user-images.githubusercontent.com/89770035/137503425-ee80329e-1c5f-4653-a8de-75e29d42191e.jpg" width="30%" height="30%"> </p>

I also came across an amazing resource called [LED Matrix Control Software HD](https://github.com/TylerTimoJ/LMCSHD). It is more of a passion project, rather than a full-on working sofware (it works rather unreliably), but it enables ju to either design the neopixel sequence usign a user friendly visual interface, or it enables you to upload a picture/gif and it will translate it into a neopixel code. 

This tool provides a lot potential for trying out different ideas and seeing how they present visually in an instant (as opposed to tediously coding any brianstormed idea you had. 

However, because the exported code uses delays (which causes problems to rest of the code), I decided to go for a different idea using the Adafruit Neomatrix library, which enable you to input flowing test. I played with the function that distorts the text (NEO_MATRIX_ZIGZAG) and I spelled out the words "Searching" and "Give up" in two sequnces. 

In terms of physical construction problems, I struggled with fixating the neopixel in a 90 degreee angle, but blue tack and a piece of cardboard turned out to be the most reliable solution. 
<p> <img src="https://user-images.githubusercontent.com/89770035/137632800-a732de64-5a7b-4156-abf3-c5021874dcd7.JPG" width="30%" height="30%"> </p>

**Servo**
<p>I had the same challenge with the servo - to make it run without using "delay". I'm still wrapping my mind around the use of millis(), and I initially wanted the servo to be part of a sequence triggered by a button, but my code made other parts of the robots unresponsive after that servo sequence. I therefore decided to use a potentiometer to control the servo. 

However, I struggled to send the potentiometer values through the radios - which is definitely something I want to learn for the final project. Unfortunately, despite many tries I had to give up and wire up the potentiometer on the same Arduino as the robot (not on the controller). It still feels like quite a failure and disappointment on my side. </p>


**Motors**
I wanted the locomotion of the robot to first go smoothly and then get stuck. Instead of coding this I just placed an external obstacle in its way while performing. This obstacle imitates externality that gets in the away, despite the code and the robot functioning smoothly. In the process, however, I had to go through the typical 

## (3) Final Version 
The final version of the robot performed as such: ran smoothly forward, got stuck, searched around for help, tried to communicate for help through the "broken" distorted neopixel text, and then slowed down the searching movement, until the distorted text sequence saying "give up" is triggered. After the flowing text stops, then the robot completely stops and the performance ends. 
<p> <img src="https://user-images.githubusercontent.com/89770035/137633648-9093591c-0a3d-4eb0-92f3-3742d063ae0c.jpg" width="40%" height="40%"> </p>


