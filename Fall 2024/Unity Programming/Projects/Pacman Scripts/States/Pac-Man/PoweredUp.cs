using UnityEngine;

public class PoweredUp : PacBaseState
{
    public PoweredUp(PacStateManager manager) : base(manager) { }

    private float timer;

    public override void EnterState()
    {
        Debug.Log("Enter State // PowerUp");

        timer = 5.0f;
    }
    
    public override void UpdateState()
    {
        if (timer > 0)
        {
            timer -= Time.deltaTime;
        }
        else
        {
            GameManager.Instance.PowerUpFinished();
            pacStateManager.SetNextState(new Normal(pacStateManager));
        }
    }
    
    public override void ExitState()
    {
        
    }
}
