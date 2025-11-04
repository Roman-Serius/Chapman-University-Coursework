using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeColorCommand : Command
{
    private CharacterController _characterController;

    public ChangeColorCommand(CharacterController characterController)
    {
        _characterController = characterController;
    }

    public void Execute()
    {
        _characterController.ChangeColor();
    }
}
