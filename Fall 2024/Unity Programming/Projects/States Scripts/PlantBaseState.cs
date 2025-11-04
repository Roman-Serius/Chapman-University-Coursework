using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class PlantBaseState
{
    protected FarmingStateManager stateManager;

    public PlantBaseState(FarmingStateManager stateManager)
    {
        this.stateManager = stateManager;
    }

    public abstract void EnterState();
    public abstract void UpdateState();
    public abstract void ExitState();
}