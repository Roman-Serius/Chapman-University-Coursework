using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
public class GameManager : MonoBehaviour
{
    public PlayerController pacmanController;
    public int Lives;
    
    private InputHandler inputHandler;
    
    private bool isPacPoweredUp;
    private bool isPacManDead;
    
    public static GameManager Instance;
    public GameObject pacMan;
    private int totalPellets;
    private int pelletsCollected;  // Amount of pellets player currently collected
    
    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // Keep this object when switching scenes
        }
        else
        {
            Destroy(gameObject); // Destroy duplicates
        }
        
        totalPellets = GameObject.FindGameObjectsWithTag("Pellet").Length;  // Counts total gameObjects in unity with tag "Pellet"
        pelletsCollected = 0;
    }

    void Start()
    {
        inputHandler = GetComponent<InputHandler>();
    }

    void Update()
    {
        ICommand command = inputHandler.HandleInput();
        if (command != null)
        {
            command.Execute(pacmanController);
        }
        
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            QuitGame();
        }
    }
    
    public void IncreasePelletCollectCount()
    {
        pelletsCollected++;
    }

    

  

    public void CheckIfAllPelletsCollected()
    {
        if (pelletsCollected == totalPellets)
        {
            LoadNextScene();
        }
    }

    public void PowerUpPacMan()
    {
        Debug.Log("Powering Up!");
        isPacPoweredUp = true;
    }

    public void PowerUpFinished()
    {
        Debug.Log("Losing Power!");
        isPacPoweredUp = false;
    }

    public bool IsPacPoweredUp()
    {
     
        return isPacPoweredUp;
    }
    
    public void SetPacManDead()
    {
        Debug.Log("PacMan is Dead!");
        isPacManDead = true;
    }
    
    public void SetPacManAlive()
    {
        Debug.Log("PacMan is Respawned!");
        isPacManDead = false;
    }

    public bool IsPacManDead()
    {
        return isPacManDead;
    }
    private void OnEnable()
    {
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        // Reset scene-specific variables here
        totalPellets = GameObject.FindGameObjectsWithTag("Pellet").Length;
        pelletsCollected = 0;
    }
    
    public void LoadNextScene()
    {
        // Get the current scene's index
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;

        // Calculate the next scene's index
        int nextSceneIndex = currentSceneIndex + 1;

        // Check if the next index is within bounds
        if (nextSceneIndex < SceneManager.sceneCountInBuildSettings)
        {
            // Load the next scene
            SceneManager.LoadScene(nextSceneIndex);
        }
        else
        {
            Debug.Log("You Win!");
        }
    }

    public IEnumerator WaitForRespawn()
    {
        pacmanController.transform.position = pacmanController.initialPos;
        
        int respawnTimer = 3;
        Debug.Log("Respawn in " + respawnTimer + " seconds...");
        
        while (respawnTimer > 0)
        {
            yield return new WaitForSeconds(1f);
            respawnTimer--;
        }
        
        SetPacManAlive();
    }

    private void QuitGame()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#endif
        Application.Quit();
    }
}
