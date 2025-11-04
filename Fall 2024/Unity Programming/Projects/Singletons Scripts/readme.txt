
Course: GAME 245: Unity Programming
Assignment: Programming Assignment #3 - Singletons
Author: Soren Marius and Pablo Bello
Marius@chapman.edu Pbello@chapman.edu
Date: October 22, 2024

Project Overview
================
This project demonstrates an Audio System using the Singleton Pattern in Unity. The system manages different audio sources across multiple scenes, providing buttons for the user to play sound effects (background music, player sounds, and world sounds), switch scenes, and quit the application.

Features
========
1. Singleton Pattern Implementation: 
   The AudioManager class uses the Singleton pattern to ensure only one instance of the AudioManager persists across scenes. This helps manage audio playback consistently throughout the application.
   

2. Scene Management:
   The application includes two demo scenes:
   - Demo: Contains buttons for playing background music, player sound, and world sound, as well as buttons for changing to Scene 2 and quitting the application.
   - Scene 2: Contains unique sound clips that differ from Scene 1 to demonstrate scene transitions with different audio content.

3. Audio Source Management:
   Each sound effect is managed by an individual AudioSource, ensuring proper playback for background music, player effects, and world sounds.

4. Extra Credit:
   Background Music is played from a seperate audio source, also under the Audio Manager so it isn't destroyed when the scene is switched.

How to Use
==========
1. Start the Application:
   When the application launches, the user is presented with Scene 1, which contains five buttons:
   - Background Music: Plays background music that continues to play across scenes.
   - Player: Plays a short sound effect.
   - World: Plays a brief sound effect.
   - Change Scene: Loads Scene 2 with new sounds attached to each button.
   - Quit: Exits the application.

2. Scene Transition:
   Press the Change Scene button to load Scene 2, which features unique sounds for each button.

3. Quit the Application:
   Use the Quit button to close the application.

Project Structure
=================
- Assets/Scripts/AudioManager.cs:
   - Implements the Singleton pattern to manage audio playback.
   - Handles persistent background music using DontDestroyOnLoad.
   - Provides methods for playing background music, player sounds, and world sounds.

- Assets/Scripts/ButtonHandler.cs:
   - Contains the logic for button actions such as changing scenes and triggering sound playback.

- Assets/Scenes/Demo.unity and Scene2.unity:
   - Two demo scenes demonstrating the sound playback system and scene transitions.



Known Issues
============
- No Known Issues

Future Improvements
===================
- NA
