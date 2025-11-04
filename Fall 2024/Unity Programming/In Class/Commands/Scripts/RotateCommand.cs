using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateCommand : Command
{
    private CharacterController _characterController;
        
    public RotateCommand(CharacterController characterController)
    {
        _characterController = characterController;
    }

    public void Execute()
    {
        _characterController.RotatePlayer();
    }
}
