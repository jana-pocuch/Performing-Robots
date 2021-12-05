# Final Project: Snow White

NOVEMBER 28
## Robot Sketches

<p>
 <img src="https://user-images.githubusercontent.com/89770035/143718853-6fd979e8-790f-48ea-9fb2-f9dae94b6a60.jpg" width="50%" height="50%"> </p>
 Sample neopixel sequences:
 <p> 
 <img src="https://user-images.githubusercontent.com/89770035/143718880-f9111e07-6b03-4381-9502-f437f0d26908.jpg" width="50%" height="50%"> 
<img src ="https://user-images.githubusercontent.com/89770035/143718882-6f2f8130-f346-4ae5-9b75-1a03c29a6a28.jpg" width ="50%" height="50%">
</p>

## Robot Description
<img src ="https://user-images.githubusercontent.com/89770035/143718921-716b92b7-a2da-4fba-8c05-60f797d8299d.jpg" width ="50%" height="50%">
</p>

## Script Outline
### Scene 2
Grumpy should be moving in a fast and sharp manner, frantically going around. Frantic arm gestures should also be included (arms would be preferrably controlled by potentiometers). The neopixel sequence would also be alternating between indifferent and very grumpy (probably two states - simple animation). Grumpy would potentially be one of the first dwarfs leading them home in a line, as he cannot wait to be alone and out of work. 

### Scene 3
Grumpy is just staring at Snow white (DC motors not moving) and then angrily throwing its hands around (with the neopixel sequnce being static on the "very grumpy" state. 

### Scene 5 (Snow White falls asleep because of the bug) 
Grumpy's arms lower, his neopixel state goes to "indifferent". He slowly moves around Snow White in confusion. 

# AND JUST LIKE THAT, DOPEY IT IS
<pre> NOVEMBER 29 - DECEMBER 6 </pre>
Due to some shceduling conflicts, me and Katie had to split up and work on separate dwarfs. The remaining one was Dopey (so I resurrected him after he got deleted from the script), and even though that I got a bit behind, I started designing him. 
Since I will have only one controller available, the functionality will be a little limited and simplistic. 
## Initial Sketch
<p><img src ="https://user-images.githubusercontent.com/89770035/144753755-23b65b32-6f73-41a9-83c0-a996410cf540.jpg" width ="50%" height="50%"></p>

## Neopixel ideas
<p><img src ="https://user-images.githubusercontent.com/89770035/144753793-ff51bd89-568e-4c05-99f8-b0e374b4b8cb.jpg" width ="50%" height="50%"></p>

## Description 
I initially wanted Dopey to have only two wheels (two DC motors) so he gives a clumsy look and feel to his character, however, in testing stages, it proved to be too unreliable. I therefore, changed it to four DC motors, one neopixel for a mouth/lips, and two small servo motors to move his big ears. In addition to these technical components, he will also have huge anime eyes, and a proper stuffed dwarf hat. His character does not talk and is supposed to give out a very confused, clumsy, but very cute impression. 

I want to use the four controller buttons for locomotion, one potentiometer for moving the ears, and the second potentiomer for possibly changing his Neopixel expression. I am afraid that the potentiometer will be a bit difficult to link with the neopixel expressions - buttons would be ideal for that. However, the controller is very limited and I think I might make it work, using three different potentiomer ranges, that would correspond with three different Neopixel expressions. 


## In the making
This was the very first attempt to build Dopey as I originally envisioned it (see the Initial Sketch). I wanted him to a vertical rectangle with two wheels), however, when I put that to test, it turned out to be very difficult for him keep balance. On the brighter note, I think I finally figured out how to attach the DC motors properly - I used pieces of cardboard to wrap the motor and glue it to the cardboard body. 
<p><img src ="https://user-images.githubusercontent.com/89770035/144754250-a3626e69-0f10-4354-91f4-8577d19a8d8b.JPG" width ="50%" height="50%"></p>

So I decided to include a rectangular base, which will have four wheels (4 DC motors) instead. This will provide for better balance, stability and make Dopey more sturdy. (the paper clips are holding the box pieces together as a temporary measure, so I can keep opening it up and accessing it). Dopey's head will be sitting on the top of this box. What is more, this will provide for more space to put all the cables, H-bridges, arduino and breadboard.

<p><img src ="https://user-images.githubusercontent.com/89770035/144754316-6dc01199-1988-4e25-bc37-f6138f3d2f77.JPG" width ="50%" height="50%"></p>

This idea turned out relatively well. I managed to attach all four DC motors (after remembering how to solder the remaining two motors, its cables and attach the H-bridge - that was quite a memory exercise, let me tell you). However, I underestimated how much space I will need to hide the arduino, batteries, breadboard anf two H-bridges. Even though that I was able to fit everything in, it was a mess and a direct recepipe for a short circuit. 

<p><img src ="https://user-images.githubusercontent.com/89770035/144754457-97a6cfa3-5392-4cbc-b0fc-9e120ac14dc1.JPG" width ="30%" height="30%">
 <img src ="https://user-images.githubusercontent.com/89770035/144754450-6cde5191-9cab-499d-9575-9995d5311c93.JPG" width ="30%" height="30%">
</p>

After getting the basis done, I worked on adding the ears and attaching them to the small servo motors, that are secured in the middle of the "face" box. 
<p><img src ="https://user-images.githubusercontent.com/89770035/144754970-a4909754-76ea-4b17-adea-c00c574f51c7.JPG" width ="50%" height="50%"></p>

And this it the final first prototype, together with a stuffed hat I made. 
<p><img src ="https://user-images.githubusercontent.com/89770035/144755033-8a8b0129-7973-42ef-9612-5ec94ce48fff.JPG" width ="50%" height="50%"></p>



