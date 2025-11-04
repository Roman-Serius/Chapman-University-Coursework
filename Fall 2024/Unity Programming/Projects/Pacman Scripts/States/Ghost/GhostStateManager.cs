using UnityEngine;
using UnityEngine.SceneManagement;

public class GhostStateManager : MonoBehaviour
{
    private GhostBaseState currentState;
    private GhostController ghostController; // Reference to the GhostController

    private void OnEnable()
    {
        SceneManager.sceneLoaded += OnSceneLoaded; // Subscribe to sceneLoaded event
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded; // Unsubscribe to avoid memory leaks
    }

    void Start()
    {
        InitializeGhostController();
        if (ghostController != null)
        {
            currentState = new Scatter(this, ghostController);
            currentState.EnterState();
        }
    }

    void Update()
    {
        if (currentState != null)
        {
            currentState.UpdateState();
        }
    }

    public void SetNextState(GhostBaseState newState)
    {
        currentState.ExitState();
        currentState = newState;
        currentState.EnterState();
    }

    private void InitializeGhostController()
    {
        // Search for a single GhostController in the scene
        ghostController = FindObjectOfType<GhostController>();

        if (ghostController != null)
        {
            Debug.Log($"GhostController found: {ghostController.name}");
        }
        else
        {
            Debug.LogWarning("No GhostController found in the scene.");
        }
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        Debug.Log($"Scene Loaded: {scene.name}");
        InitializeGhostController();

        // Reinitialize state if needed
        if (ghostController != null && currentState == null)
        {
            currentState = new Scatter(this, ghostController);
            currentState.EnterState();
        }
    }
}