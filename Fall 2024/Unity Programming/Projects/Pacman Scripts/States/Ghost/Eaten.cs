using UnityEngine;

public class Eaten : GhostBaseState
{
    private Vector3 basePosition; // The ghost's base position
    private GhostController ghostController;

    public Eaten(GhostStateManager manager, GhostController controller) : base(manager)
    {
        ghostController = controller;
        basePosition = ghostController.basePosition;
    }
    

    public override void EnterState()
    {
        Debug.Log("Enter State // Eaten");
        

        ghostController.GetComponent<Animator>().SetBool("isDead", true);
        
       

        // Direct the ghost to its base
        ghostController.SetTarget(basePosition);

        // Optionally adjust ghost's speed for the Eaten state
        ghostController.speed = 5f; // Higher speed to quickly return to base
    }

    public override void UpdateState()
    {
        // Check if the ghost has reached the base
        if (Vector3.Distance(ghostController.transform.position, basePosition) < 0.1f)
        {
            Debug.Log("Ghost has reached the base. Respawning...");
            ghostStateManager.SetNextState(new RespawnGhost(ghostStateManager, ghostController));
        }
    }

    public override void ExitState()
    {
        Debug.Log("Exit State // Eaten");

        // Reset the ghost's speed to its normal value
        ghostController.speed = 2f; // Default speed for normal behavior
    }
}