using UnityEngine;

public class Scatter : GhostBaseState
{
    private GhostController ghostController;
    private Vector3 scatterTarget; // Target position for the Scatter state

    public Scatter(GhostStateManager manager, GhostController controller) : base(manager)
    {
        ghostController = controller;

        // Assign scatter target based on the ghost's type or identity
        scatterTarget = AssignScatterTarget();
    }

    public override void EnterState()
    {
        Debug.Log("Enter State // Scatter");

        // Set the scatter animation or behavior
        ghostController.GetComponent<Animator>().SetBool("isFrightened", false);

        // Set ghost to move toward the scatter target
        ghostController.SetTarget(scatterTarget);
    }

    public override void UpdateState()
    {
        Debug.Log("Scatter update");
        // Transition to Frighten if Pac-Man is powered up
        if (GameManager.Instance.IsPacPoweredUp())
        {
            Debug.Log("Attempting to frighten");
            ghostStateManager.SetNextState(new Frighten(ghostStateManager, ghostController));
        }

        // Optional: Add condition to switch back to Chase state if desired
    }
    
    public override void ExitState()
    {
        Debug.Log("Exit State // Scatter");
    }

    private Vector3 AssignScatterTarget()
    {
        // Example logic for assigning scatter target
        switch (ghostController.name)
        {
            case "Blinky": return new Vector3(10, 10, 0); // Top-right corner
            case "Pinky": return new Vector3(-10, 10, 0); // Top-left corner
            case "Inky": return new Vector3(10, -10, 0); // Bottom-right corner
            case "Clyde": return new Vector3(-10, -10, 0); // Bottom-left corner
            default: return new Vector3(0, 0, 0); // Default scatter target
        }
    }
}