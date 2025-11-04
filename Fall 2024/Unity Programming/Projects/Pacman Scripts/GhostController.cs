using UnityEngine;
using Random = UnityEngine.Random;

public class GhostController : MonoBehaviour
{
    public Vector3 basePosition; // Assign in Inspector or initialize at runtime
    public float speed; // Control ghost movement speed
    private Vector2 direction; // Current movement direction
    private Vector3 targetGridPosition; // Target grid position
    private Animator animator;

    private void Awake()
    {
        animator = GetComponent<Animator>();
        
        // Snap Pac-Man to the nearest grid point at the start
        targetGridPosition = SnapToGrid(transform.position);
        transform.position = targetGridPosition;
        
        // Initialize direction at random
        ChooseRandomDirection();
    }

    private void FixedUpdate()
    {
        Move();
    }

    private void Move()
    {
        // If the ghost reaches the target grid position, evaluate the next direction
        if (Vector3.Distance(transform.position, targetGridPosition) < 0.01f)
        {
            transform.position = targetGridPosition; // Snap to grid

            // Check if the current direction is valid; if not, choose a new direction
            if (!CanMove(direction))
            {
                ChooseRandomDirection();
            }

            // Update the target grid position based on the new direction
            targetGridPosition += (Vector3)direction;
        }

        // Move the ghost toward the target grid position
        transform.position = Vector3.MoveTowards(transform.position, targetGridPosition, speed * Time.fixedDeltaTime);
    }
    
    private bool CanMove(Vector2 dir)
    {
        // Use the target grid position for collision checks
        Vector3 checkPosition = targetGridPosition + (Vector3)dir;

        // Perform a small raycast check
        float rayDistance = 0.1f;
        RaycastHit2D hit = Physics2D.Raycast(checkPosition, Vector2.zero, rayDistance, LayerMask.GetMask("Walls"));
        return hit.collider == null;
    }
    
    private void ChooseRandomDirection()
    {
        Vector2[] possibleDirections = { Vector2.up, Vector2.down, Vector2.left, Vector2.right };
        direction = Vector2.zero;

        // Keep choosing a direction until a valid one is found
        while (direction == Vector2.zero)
        {
            Vector2 randomDirection = possibleDirections[Random.Range(0, possibleDirections.Length)];
            if (CanMove(randomDirection))
            {
                direction = randomDirection;
                
                // Update animator for the new direction
                animator.SetFloat("moveX", direction.x);
                animator.SetFloat("moveY", direction.y);
            }
        }
    }

    public void SetTarget(Vector3 targetPosition)
    {
        targetGridPosition = SnapToGrid(targetPosition);
    }

   private Vector3 SnapToGrid(Vector3 position)
    {
        return new Vector3(
            Mathf.Round(position.x),
            Mathf.Round(position.y),
            position.z // Preserve z-axis for 2D
        );
    }
}
