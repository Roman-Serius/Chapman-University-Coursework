using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerController : MonoBehaviour
{
    public Vector2 initialPos; // Track Pac-Man's orginial position
    private Vector2 direction; // Current movement direction
    private Vector2 nextDirection; // Direction to switch to based on input
    public float speed = 5f;
    private Animator animator;
    private Vector3 targetGridPosition; // Target grid position
    private static PlayerController instance;
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
        animator = GetComponent<Animator>();
        ResetPosition();
        initialPos = transform.position;

        // Snap Pac-Man to the nearest grid point at the start
        targetGridPosition = SnapToGrid(transform.position);
        transform.position = targetGridPosition;
    }
    private void OnEnable()
    {
        ResetPosition();
        SceneManager.sceneLoaded += OnSceneLoaded; // Subscribe to scene loaded event
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded; // Unsubscribe to avoid memory leaks
    }


    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        ResetPosition();
        targetGridPosition = transform.position;
    }
    private void ResetPosition()
    {
        transform.position = Vector3.zero; // Reset player to (0, 0, 0)
        Debug.Log("Player position reset to (0, 0)");
    }

    void FixedUpdate()
    {
        if (!GameManager.Instance.IsPacManDead())
        {
            Move(); 
        }
        
        
    }

    public void SetNextDirection(Vector2 dir, int x, int y)
    {
        // Only allow changing direction if the target direction is valid
        if (CanMove(dir))
        {
            nextDirection = dir;

            // Update animator for the new direction
            animator.SetFloat("moveX", x);
            animator.SetFloat("moveY", y);

            if (x == 0 && y == 0)
            {
                animator.SetBool("isMoving", false);
            }
            else
            {
                animator.SetBool("isMoving", true);
            }
        }
    }

    public void RespawnPacMan()
    {
        // This function gets called from RespawnPacMan state
        direction = Vector2.zero;
        SetNextDirection(Vector2.zero, 0, 0);
       
        StartCoroutine(GameManager.Instance.WaitForRespawn());
        targetGridPosition = Vector3.zero;
        
    }

    void Move()
    {
        // If at the target grid position, evaluate direction
        if (Vector3.Distance(transform.position, targetGridPosition) < 0.01f)
        {
            transform.position = targetGridPosition; // Snap to grid
            direction = CanMove(nextDirection) ? nextDirection : (CanMove(direction) ? direction : Vector2.zero);

            // If Pac-Man can't move, stop animations
            if (direction == Vector2.zero)
            {
                animator.SetBool("isMoving", false);
                return;
            }

            // Update target grid position based on the new direction
            targetGridPosition += (Vector3)direction;
        }

        // Move Pac-Man toward the target grid position
        transform.position = Vector3.MoveTowards(transform.position, targetGridPosition, speed * Time.fixedDeltaTime);
    }

    Vector3 SnapToGrid(Vector3 position)
    {
        return new Vector3(
            Mathf.Round(position.x),
            Mathf.Round(position.y),
            position.z // Preserve z-axis for 2D
        );
    }

    bool CanMove(Vector2 dir)
    {
        // Use the target grid position for collision checks
        Vector3 checkPosition = targetGridPosition + (Vector3)dir;

        // Perform a small raycast check
        float rayDistance = 0.5f;
        Debug.DrawRay(checkPosition, Vector3.zero, Color.red, 0.1f); // Visualize the ray
        RaycastHit2D hit = Physics2D.Raycast(checkPosition, Vector2.zero, rayDistance, LayerMask.GetMask("Walls"));
        return hit.collider == null;
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        // Collect pellets
        if (other.gameObject.CompareTag("Pellet"))
        {
            Debug.Log("Pellet Collect");
            
            other.gameObject.SetActive(false);
            GameManager.Instance.IncreasePelletCollectCount();
            GameManager.Instance.CheckIfAllPelletsCollected();
        }

        // Collect power pellets
        if (other.gameObject.CompareTag("PowerPellet"))
        {
            Debug.Log("Power Up!");
            
            other.gameObject.SetActive(false);
            GameManager.Instance.PowerUpPacMan();
        }

        // Pac dies when contact with Ghost at normal state
        if (other.gameObject.CompareTag("Ghost"))
        {
            Debug.Log("Dead");

            if (!GameManager.Instance.IsPacPoweredUp())
            {
                GameManager.Instance.SetPacManDead();
            }
        }
    }
}