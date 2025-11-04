using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EventController : MonoBehaviour
{
    public Enemy enemyPrefab;

    private int score = 0;

    private int numberOfEnemies = 0;
    // Start is called before the first frame update
    void Awake()
    {
        Enemy.onDeath += AddToScore;
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            GameObject newEnemy = Instantiate(enemyPrefab.gameObject);
            
            Destroy(newEnemy, 3f);
        }
    }

    void AddToScore(Enemy enemyScript)
    {
        score += enemyScript.enemyValue;

        numberOfEnemies += 1;
        
        Debug.Log($"You've killed {numberOfEnemies} enemies, and your score is {score}.");
    }
}
