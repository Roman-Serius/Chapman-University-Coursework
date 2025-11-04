using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlantState : PlantBaseState
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    public PlantState(FarmingStateManager stateManager) : base(stateManager)
    {
    }

    public override void EnterState()
    {
        stateManager.SetImage(3);
        stateManager.EnableButton(4);
        stateManager.EnableButton(5);
        stateManager.EnableButton(6);
    }

    public override void UpdateState()
    {
        
    }

    public override void ExitState()
    {
       
    }
}
