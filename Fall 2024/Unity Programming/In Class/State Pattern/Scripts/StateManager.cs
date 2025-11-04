using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StateManager : MonoBehaviour
{
    private BaseState currentState;

    public Material[] materials;

    public GameObject[] objects;
    // Start is called before the first frame update
    void Start()
    {
        currentState = new RedLight(this);
        currentState.EnterState();
    }

    // Update is called once per frame
    void Update()
    {
        currentState.UpdateState();
    }

    public void SetNextState(BaseState nextState)
    {
        currentState.ExitState();
        currentState = nextState;
        currentState.EnterState();
    }

    public void SetMaterial(int objectIndex, int materialIndex)
    {
        GameObject lightObject = objects[objectIndex];
        Material lightMaterial = materials[materialIndex];

        lightObject.GetComponent<Renderer>().material = lightMaterial;
    }
}
