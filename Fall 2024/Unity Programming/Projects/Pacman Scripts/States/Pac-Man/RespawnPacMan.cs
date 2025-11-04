using UnityEngine;

public class RespawnPacMan : PacBaseState
{
    public RespawnPacMan(PacStateManager manager) : base(manager) { }

    public override void EnterState()
    {
        Debug.Log("Enter State // RespawnPacMan");
        
        // Respawn PacMan
        pacStateManager.playerController.RespawnPacMan();
    }

    public override void UpdateState()
    {
        if (!GameManager.Instance.IsPacManDead())
        {
            pacStateManager.SetNextState(new Normal(pacStateManager));
        }
    }
    
    public override void ExitState() { }
}
