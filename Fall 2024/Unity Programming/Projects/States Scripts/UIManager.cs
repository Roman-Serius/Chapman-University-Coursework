using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    private bool timerRunning;
    public float timeRemaining;
    public Text timerText;
    public FarmingStateManager farmingStateManager;
    public Text countText;
    private int count = 0;
    public GameObject infoPanel;

    public Button[] buttons;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    void Update()
    {
        if (timerRunning)
        {
            if (timeRemaining > 0)
            {
                timeRemaining -= Time.deltaTime;  // Decrease time remaining by delta time
                UpdateTimerDisplay(timeRemaining);
            }
            else
            {
                timeRemaining = 0;               // Clamp to zero
                timerRunning = false;            // Stop the timer
                TimerFinished();
            }
        }
    }

   

    public void EnableButton(int buttonIndx)
    {
        buttons[buttonIndx].gameObject.SetActive(true);
    }

    public void DisableButton(int buttonIndx)
    {
        if (buttons != null && buttonIndx >= 0 && buttonIndx < buttons.Length)
        {
            if (buttons[buttonIndx] != null)
            {
                if (buttons[buttonIndx].gameObject.activeSelf)
                {
                    buttons[buttonIndx].gameObject.SetActive(false);
                }
            }
            else
            {
                Debug.LogWarning("Button at index " + buttonIndx + " is null in the buttons array.");
            }
        }
        else
        {
            Debug.LogWarning("Button index " + buttonIndx + " is out of range or buttons array is not assigned.");
        }
    }

    public void StartTimer()
    {
        timeRemaining = 10f;             // Reset the timer to 1 minute
        timerRunning = true;
    }
    
    void UpdateTimerDisplay(float time)
    {
        int minutes = Mathf.FloorToInt(time / 60); // Get minutes
        int seconds = Mathf.FloorToInt(time % 60); // Get seconds
        timerText.text = string.Format("{0:00}:{1:00}", minutes, seconds); // Format as mm:ss
    }

    public void UpdateCounter()
    {
        count += 1;
        countText.text = "Harvested: " + count;
    }
    
    void TimerFinished()
    {
        
        farmingStateManager.AfterTimer();
        StartTimer();
        
    }


    public void DisableInfoPanel()
    {
        infoPanel.SetActive(false);
    }

    public void EnableInfoPanel()
    {
        infoPanel.SetActive(true);
    }
    public void Quit()
    {
        Application.Quit();
    }
}
