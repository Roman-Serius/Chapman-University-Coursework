using System.Collections.Generic;
using UnityEngine;

public class InputHandler : MonoBehaviour
{
    private Dictionary<KeyCode, ICommand> commandMap;

    void Start()
    {
        commandMap = new Dictionary<KeyCode, ICommand>
        {
            { KeyCode.W, new MoveUpCommand() },
            { KeyCode.S, new MoveDownCommand() },
            { KeyCode.A, new MoveLeftCommand() },
            { KeyCode.D, new MoveRightCommand() }
        };
    }

    public ICommand HandleInput()
    {
        foreach (var entry in commandMap)
        {
            if (Input.GetKeyDown(entry.Key))
            {
                return entry.Value;
            }
        }
        return null;
    }
}
