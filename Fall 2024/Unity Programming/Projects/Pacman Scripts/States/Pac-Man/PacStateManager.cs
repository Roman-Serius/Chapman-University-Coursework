using UnityEngine;

public class PacStateManager : MonoBehaviour
{
    public PlayerController playerController;
    private PacBaseState currentState;

    void Start()
    {
        Debug.Log("Pac State Manager // Initialized");

        currentState = new Normal(this);
        currentState.EnterState();
    }

    void Update()
    {
        currentState.UpdateState();
    }
    
    public void SetNextState(PacBaseState nextState)
    {
        currentState.ExitState();
        currentState = nextState;
        currentState.EnterState();
    }
}
