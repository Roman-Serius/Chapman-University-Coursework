using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public static event Action<Enemy> onDeath;
    
    public int enemyValue { get; private set; }

    private void OnDisable()
    {
        enemyValue = UnityEngine.Random.Range(1, 5);

        onDeath?.Invoke(this);
    }
}
