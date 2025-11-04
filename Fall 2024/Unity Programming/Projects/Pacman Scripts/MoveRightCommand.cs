using UnityEngine;

public class MoveRightCommand : ICommand
{
    public void Execute(PlayerController pacman)
    {
        pacman.SetNextDirection(Vector2.right, 1, 0);
    }
}
