using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CloseGameCommand : Command
{
    private GameController _gameController;

    public CloseGameCommand(GameController gameController)
    {
        _gameController = gameController;
    }

    public void Execute()
    {
        _gameController.CloseGame();
    }
}
