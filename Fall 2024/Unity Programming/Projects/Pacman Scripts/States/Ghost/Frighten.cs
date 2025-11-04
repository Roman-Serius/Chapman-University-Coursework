using UnityEngine;

public class Frighten : GhostBaseState
{
    private GhostController ghostController;

    public Frighten(GhostStateManager manager, GhostController controller) : base(manager)
    {
        ghostController = controller; // Pass GhostController reference
    }

    public override void EnterState()
    {
        Debug.Log("Enter State // Frighten");

        // Set animator to play the frightened animation
        ghostController.GetComponent<Animator>().SetBool("isFrightened", true);
        
        // Optionally, reduce ghost speed during frighten state
        ghostController.speed *= 0.5f; // Halve the speed
    }

    public override void UpdateState()
    {
        // Exit Frighten state when Pac-Man loses power-up
        if (!GameManager.Instance.IsPacPoweredUp())
        {
            ghostStateManager.SetNextState(new Scatter(ghostStateManager, ghostController));
        }

        // Enter Eaten state if the ghost is eaten by Pac-Man
        if (ghostController.GetComponent<Collider2D>().IsTouching(GameManager.Instance.pacMan.GetComponent<Collider2D>()))
        {
            ghostStateManager.SetNextState(new Eaten(ghostStateManager, ghostController));
        }
    }

    public override void ExitState()
    {
        Debug.Log("Exit State // Frighten");

        // Reset animator and ghost speed
        // ghostController.GetComponent<Animator>().SetBool("isFrightened", false);
        ghostController.speed *= 2.0f; // Restore original speed
    }
}