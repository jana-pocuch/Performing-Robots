# Midterm Project
## Initial Brainstorm
For this project I want to build a robot that is not humanoid. I do not want to rely on the humanoid form to imitate human like limb movements and face expression - and want to invent a unique form of expression for the robot, which seems slightly more challenging and experimental. 

The whole semester I've been collecting materials (even though one might easily mistake the collection for trash - I own more bottle caps than I'm willing to admit at this point). And one of the boxes I kept from the NYUAD 10th anniversary D2 cupcakes particularly inspired me. I started sketching initial ideas of how it could move and perform, then tried building it, then I sketched again, built again, sketched again and built again. At first I though I might use the moving servo flower from my previous project, however, when building, I discoverd building a "servo neck" creates a lot more potential for expression. Currently I am in the fourth phase or reiteration, and will probably end up reiterating at least 896 times more. 

<p> <img src="https://user-images.githubusercontent.com/89770035/135754802-44bb9414-7e68-42ff-a538-a9b68385964b.jpg" width="75%" height="75%"> </p>

And this is how the first vs. fourth prototypes looked like in real life:
<p> <img src="https://user-images.githubusercontent.com/89770035/135755194-b1f56536-9980-44e9-bb62-8d2f3774fc9f.JPG" width="30%" height="30%"> <img src="https://user-images.githubusercontent.com/89770035/135755197-cff7ba2f-e708-4ddd-9c1c-8ea69fc0a8b0.JPG" width="30%" height="30%"> </p>

## Expression
My robot will be mainly communicating through the movement of its little head (controlled by a servo), and its face (the Neomatrix). My idea for the sequence is for the robot to be frantically looking around, taking sharp turns and blinking rapidly, which then transitions into "giving up". This transition will be done through slowing down/stopping the motor movement, slowing down the servo turning, and through decrease in the color saturation, brightness and patterns on the Neomatrix. 

## Problems
In terms of building, I experience some of the "classic" troubles we discussed a lot in class: major one of which was tilting of the base that holds the two motors. I want the robot to be as small as possible (because cuteness), so I am only using two wheels. After a few different attempts with sizing the cardboard base and placing the wheels strategically, putting a toilet paper roll in the middle turned out to be the most stable and reliable solution, that allowed the robot to stay relatively small.

<p> <img src="https://user-images.githubusercontent.com/89770035/135755303-40692687-f5e2-49b3-96ee-11859b009405.JPG" width="30%" height="30%"> </p>

Since I am still in the reiterating phase, I am using a lot of adhesive tack for the servo motor to stay in place as well as for holding the box. Glueing them is a committment I am not ready for at this stage just yet. 

I am also using tack for holding the Neopixel in place, but that one, as opposed to the servo and the box, is veeeeery unstable. I still need to figure out a way how to hold the Neopixel in an upright position in the plastic window of the box. But for now, I still need it to be mobile as I am taking things in and out and rewiring, so I have some time to sit on it and think about how to fixate it. 

However, the biggest problem I faced is my lack of coding skills :))) I managed to work on small sequences separately (motors, servos and Neopixel), but the moment I try to paste it all together is where it collapses. I also feel like I am just using sample codes from Arduino and from our class and feel very restricted when it comes to writing code myself (especially for the Neopixel animation). I spent several hours trying to understand how the sample codes work, but I did not manage to understand it to the extent I would be able to put my own visual animation idea into code. So, unfortunatelly, this seems like the biggest obstacle so far, that I will need to spend a lot of time on, just doing endless loops of trial and error. 


