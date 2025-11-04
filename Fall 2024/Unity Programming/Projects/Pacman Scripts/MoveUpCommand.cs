using UnityEngine;


    public class MoveUpCommand : ICommand
    {
        public void Execute(PlayerController pacman)
        {
            pacman.SetNextDirection(Vector2.up, 0, 1);
        }
    }

