using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveCommand : Command
{
    private CharacterController _characterController;

    public MoveCommand(CharacterController characterController)
    {
        _characterController = characterController;
    }

    public void Execute()
    {
        _characterController.MovePlayer();
    }

    public static string Direction;
}
