using UnityEngine;

public class Death : PacBaseState
{
    public Death(PacStateManager manager) : base(manager) { }

  

    public override void EnterState()
    {
        Debug.Log("Enter State // Death");
       
        
        
        GameManager.Instance.SetPacManDead();
        
        
    }

    public override void UpdateState()
    {
        pacStateManager.SetNextState(new RespawnPacMan(pacStateManager));
    }
    
    public override void ExitState() { }
}
