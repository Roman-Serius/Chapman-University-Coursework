//Soren Marius
// 002456139
// Marius@chapman.edu
// GAME-245-02
// Assignment1
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Countdown Countdown;
    public UpdateText UpdateText;

    
    //Start Game Button Calls this
    public void Begin()
    {
        Countdown.StartCountdown();
        
    }

    
    //Quit button calls this
    public void quitGame()
    {
        Application.Quit();
    }
}
