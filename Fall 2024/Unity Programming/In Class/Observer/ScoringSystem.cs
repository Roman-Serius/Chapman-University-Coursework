using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScoringSystem : MonoBehaviour, IObserver
{
    [Header("Subject Variable")]
    [SerializeField] Subject _eventSubject;

    int score = 0;
    public void OnNotify()
    {
        //Debug.Log("Scoring System Initialized");
        score++;
        Debug.Log("Score: " + score);
    }

    private void OnEnable()
    {
        _eventSubject.AddObserver(this);
    }

    private void OnDisable()
    {
        _eventSubject.RemoveObserver(this);
    }
}
