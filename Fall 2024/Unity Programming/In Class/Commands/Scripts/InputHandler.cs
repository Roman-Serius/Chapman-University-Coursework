using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

public class InputHandler : MonoBehaviour
{
    public CharacterController _characterController;
    public GameController _gameController;

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            Command storedCommand = new RotateCommand(_characterController);
            storedCommand.Execute();
        }

        if (Input.GetKeyDown(KeyCode.RightArrow) || Input.GetKeyDown(KeyCode.A))
        {
            MoveCommand.Direction = "Right";
            Command storedCommand = new MoveCommand(_characterController);
            storedCommand.Execute();
        }
        
        if (Input.GetKeyDown(KeyCode.LeftArrow) || Input.GetKeyDown(KeyCode.D))
        {
            MoveCommand.Direction = "Left";
            Command storedCommand = new MoveCommand(_characterController);
            storedCommand.Execute();
        }

        if (Input.GetKeyDown(KeyCode.Escape))
        {
            
            Command storedCommand = new CloseGameCommand(_gameController);
            storedCommand.Execute();

        }

        if (Input.GetKeyDown(KeyCode.Space) && !CharacterController.isJumping)
        {
            Command storedCommand = new JumpCommand(_characterController);
            storedCommand.Execute();
        }
        
        if (Input.GetKeyDown(KeyCode.C))
        {
            Command storedCommand = new ChangeColorCommand(_characterController);
            storedCommand.Execute();
        }

    }
}
