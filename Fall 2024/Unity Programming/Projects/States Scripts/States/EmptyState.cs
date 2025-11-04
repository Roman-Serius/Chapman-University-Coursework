using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EmptyState : PlantBaseState
{
  

    public EmptyState(FarmingStateManager stateManager) : base(stateManager)
    {
    }

    public override void EnterState()
    {
        stateManager.SetImage(0);
        stateManager.EnableButton(3);
        stateManager.DisableButton(4);
        stateManager.DisableButton(5);
        stateManager.DisableButton(6);
    }

    public override void UpdateState()
    {
        
    }

    public override void ExitState()
    {
        
    }
}
