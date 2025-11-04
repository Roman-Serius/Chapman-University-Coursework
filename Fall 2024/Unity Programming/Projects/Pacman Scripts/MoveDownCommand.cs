using UnityEngine;

public class MoveDownCommand : ICommand
{
    public void Execute(PlayerController pacman)
    {
        pacman.SetNextDirection(Vector2.down, 0, -1);
    }
}