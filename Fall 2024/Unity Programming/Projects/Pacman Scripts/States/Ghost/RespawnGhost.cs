using UnityEngine;

public class RespawnGhost : GhostBaseState
{
    private float timer;
    private GhostController ghostController;

    public RespawnGhost(GhostStateManager manager, GhostController controller) : base(manager)
    {
        ghostController = controller;
    }

    public override void EnterState()
    {
        Debug.Log("Enter State // RespawnGhost");

        // Initialize timer
        timer = 5.0f;

        // Reset ghost to base position and stop movement
        ghostController.transform.position = ghostController.basePosition;
        ghostController.SetTarget(ghostController.basePosition); // Stay at base

        // Set animation to idle or respawning
        ghostController.GetComponent<Animator>().SetBool("isDead", false);
        ghostController.GetComponent<Animator>().SetBool("isFrightened", false);
        ghostController.GetComponent<SpriteRenderer>().sprite = null;

        // Reduce ghost speed to 0 during idle state
        ghostController.speed = 0f;
    }

    public override void UpdateState()
    {
        if (timer > 0)
        {
            timer -= Time.deltaTime;
        }
        else
        {
            // Transition back to Scatter state
            ghostStateManager.SetNextState(new Scatter(ghostStateManager, ghostController));
        }
    }

    public override void ExitState()
    {
        Debug.Log("Exit State // RespawnGhost");

        // Restore default ghost speed
        ghostController.speed = 2f; // Default speed
    }
}