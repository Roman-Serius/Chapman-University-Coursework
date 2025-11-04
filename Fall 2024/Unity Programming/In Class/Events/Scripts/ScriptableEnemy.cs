using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Enemy", menuName = "ScriptableObjects/EnemyScriptableObject", order = 1)]
public class ScriptableEnemy : ScriptableObject
{
    public static event Action<ScriptableEnemy> onDeath;

    public int Test;
    public int enemyValue { get; private set; }

    private void OnDisable()
    {
        enemyValue = UnityEngine.Random.Range(1, 5);

        onDeath?.Invoke(this);
    }
}
