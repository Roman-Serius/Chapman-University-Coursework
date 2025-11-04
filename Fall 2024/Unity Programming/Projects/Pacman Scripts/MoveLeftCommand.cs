using UnityEngine;

public class MoveLeftCommand : ICommand
{
    public void Execute(PlayerController pacman)
    {
        pacman.SetNextDirection(Vector2.left, -1, 0);
    }
}
