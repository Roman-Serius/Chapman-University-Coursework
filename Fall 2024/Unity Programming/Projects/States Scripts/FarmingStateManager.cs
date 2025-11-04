using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Mime;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

public class FarmingStateManager : MonoBehaviour
{
    public Sprite[] sprites;

    public GameObject plot;

    public Boolean isWatered;
    
    public UIManager uiManager;
    public enum PlantStates
    {
        Empty,
        Seed,
        Seedling,
        Plant,
        Dead
    }
    private PlantBaseState currentState;

    public void Water()
    {
        isWatered = true;
    }

    public void AfterTimer()
    {
        if (isWatered)
        {
            if (currentState is SeedState)
            {
                SetNextState(2);
            }

            else if (currentState is SeedlingState)
            {
                SetNextState((3));
            }
          
        }
        else
        {
            if (!(currentState is EmptyState) && !(currentState is SeedState))
            {
                SetNextState(4);
            }
        }

        isWatered = false;
    }
    
    public void SetNextState(int newState)
    {
        PlantStates state = (PlantStates)newState;
        if (currentState != null)
        {
            currentState.ExitState();  // Exit the current state
        }

        switch (state)
        {
            case PlantStates.Empty:
                currentState = new EmptyState(this);
                break;
            case PlantStates.Seed:
                currentState = new SeedState(this); 
                break;
            case PlantStates.Seedling:
                currentState = new SeedlingState(this);  
                break;
            case PlantStates.Plant:
                currentState = new PlantState(this);  
                break;
            case PlantStates.Dead:
                currentState = new DeadState(this);  
                break;
        }

        currentState.EnterState();
        uiManager.StartTimer();
    }

    

    // Update is called once per frame
    void Update()
    {
        
    }
    

    public void SetImage(int spriteIndex)
    {
        Sprite sprite = sprites[spriteIndex];
        plot.GetComponent<Image>().sprite = sprite;
    }

    public void EnableButton(int buttonIndx)
    {
        uiManager.EnableButton(buttonIndx);
    }

    public void DisableButton(int buttonIndx)
    {
        uiManager.DisableButton(buttonIndx);
    }
    
}
