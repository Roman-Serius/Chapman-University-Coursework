using UnityEngine;

public class Normal : PacBaseState
{
    public Normal(PacStateManager manager) : base(manager) { }

    public override void EnterState() { Debug.Log("Enter State // Normal"); }

    public override void UpdateState()
    {
        if (GameManager.Instance.IsPacPoweredUp())
        {
            pacStateManager.SetNextState(new PoweredUp(pacStateManager));
        }
        else if (GameManager.Instance.IsPacManDead())
        {
            pacStateManager.SetNextState(new Death(pacStateManager));
        }
    }
    public override void ExitState() { }
}
