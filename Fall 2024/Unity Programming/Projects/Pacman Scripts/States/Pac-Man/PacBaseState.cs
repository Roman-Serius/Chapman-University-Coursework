public abstract class PacBaseState
{
    protected PacStateManager pacStateManager;

    public PacBaseState(PacStateManager pacStateManager)
    {
        this.pacStateManager = pacStateManager;
    }

    public abstract void EnterState();
    public abstract void UpdateState();
    public abstract void ExitState();
}
