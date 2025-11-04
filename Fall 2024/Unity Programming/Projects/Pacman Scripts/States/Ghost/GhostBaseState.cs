public abstract class GhostBaseState
{
    protected GhostStateManager ghostStateManager;

    public GhostBaseState(GhostStateManager ghostStateManager)
    {
        this.ghostStateManager = ghostStateManager;
    }

    public abstract void EnterState();
    public abstract void UpdateState();
    public abstract void ExitState();
}
