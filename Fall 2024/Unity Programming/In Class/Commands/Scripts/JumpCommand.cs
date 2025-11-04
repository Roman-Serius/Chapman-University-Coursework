using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JumpCommand : Command
{
    private CharacterController _characterController;

    public JumpCommand(CharacterController characterController)
    {
        _characterController = characterController;
    }

    public void Execute()
    {
        _characterController.Jump();
    }
}
