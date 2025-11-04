using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeadState : PlantBaseState
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public DeadState(FarmingStateManager stateManager) : base(stateManager)
    {
    }
    public override void EnterState()
    {
        stateManager.SetImage(4);
        stateManager.DisableButton(4);
        stateManager.DisableButton(5);
        stateManager.EnableButton(6);
    }

    public override void UpdateState()
    {
        
    }

    public override void ExitState()
    {
       
    }
}
