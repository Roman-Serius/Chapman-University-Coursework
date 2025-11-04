using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using TMPro;

public class UpdateText : MonoBehaviour
{
   public TMP_Text Text;

   //called by Countdown
   public void TextEdit(string newText)
   {
      Text.SetText(newText);
   }

 

  
}
