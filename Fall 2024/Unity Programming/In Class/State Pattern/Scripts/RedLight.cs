using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RedLight : BaseState 
{
    public RedLight(StateManager manager) : base(manager){}
    public override void EnterState()
    {
        stateManager.SetMaterial(0,0);
    }

    public override void UpdateState()
    {
        
    }

    public override void ExitState()
    {
        stateManager.SetMaterial(0,3);
    }
}
