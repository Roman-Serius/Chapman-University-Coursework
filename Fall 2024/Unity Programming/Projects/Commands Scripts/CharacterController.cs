using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class CharacterController : MonoBehaviour
{
    public float jumpForce = 2.0f;  
    public float fallSpeed = 1.0f;
    public static bool isJumping = false;
    private float jumpCooldown = 2.0f;  
    private float jumpTimer = 0f;
    private Rigidbody rb;
    private Renderer objectRenderer;
    private Vector3 direction;
    private float minX, maxX;

    private void Start()
    {
        rb = GetComponent<Rigidbody>();
        
        objectRenderer = GetComponent<Renderer>();
    }
    public void RotatePlayer()
    {
        transform.Rotate(Vector3.up, 45f);
    }

    public void MovePlayer()
    {
        if (MoveCommand.Direction == "Right")
        {
            transform.Translate(Time.deltaTime,0,0);
        }
        else
        {
            transform.Translate(-Time.deltaTime,0,0);
        }
        
    }
    
    public void Jump()
    {
        isJumping = true;
        rb.MovePosition(new Vector3(transform.position.x, transform.position.y + jumpForce, transform.position.z));
    }
    
    public void ChangeColor()
    {
        // Generate a random color
        Color newColor = new Color(Random.value, Random.value, Random.value);
        
        // Set the new color to the material of the GameObject
        objectRenderer.material.color = newColor;
    }

    private void Update()
    {
        if (isJumping)
        {
            jumpTimer += Time.deltaTime;

            // Fall mechanism, after 1 second reduce height by 1 unit per second
            if (jumpTimer >= 1.0f && jumpTimer < jumpCooldown)
            {
                rb.MovePosition(new Vector3(transform.position.x, transform.position.y - fallSpeed * Time.deltaTime,
                    transform.position.z));
            }

            // End jump after 2 seconds
            if (jumpTimer >= jumpCooldown)
            {
                isJumping = false;
                jumpTimer = 0f;
            }
        }
    }
}
