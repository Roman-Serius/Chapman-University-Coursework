using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Countdown Countdown;
    public UpdateText UpdateText;

    //Triggers on start game button press
    public void Begin()
    {
        Countdown.StartCountdown();
        
    }

    
    //Triggers on Quit game button press
    public void quitGame()
    {
        Application.Quit();
    }
}
