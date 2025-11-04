using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SeedlingState : PlantBaseState
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    public SeedlingState(FarmingStateManager stateManager) : base(stateManager)
    {
    }

    public override void EnterState()
    {
        Debug.Log("Entered SeedlingState");
        stateManager.SetImage(2);
        stateManager.EnableButton(4);
        stateManager.EnableButton(6);
    }

    public override void UpdateState()
    {
        
    }

    public override void ExitState()
    {
        
    }
}
