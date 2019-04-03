using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Web;
using System.Web.Mvc;
using WebApplication3.Models;

namespace WebApplication3.Controllers
{
    public class UserController : Controller
    {
        // GET: User
        public string Login()
        {

            return "hellooo";
        }

        [HttpPost]
        public string Login1(User l,JsonResult json)
        {
            string apiURI = "http://51149:/api/login";
            
            var client = new HttpClient();
            var values = new Dictionary<string, string>()
            {
                {"email_id",l.email_id },
                {"password",l.password }
            };
            var content = new FormUrlEncodedContent(values);
            var response = client.PostAsync(apiURI, content);
            if (response.Result.IsSuccessStatusCode)
            {
                return "success";
            }
            else
            {
                ModelState.AddModelError(string.Empty, "server error.plase contact adminstrator");
                return "failed";
            }

            
        }
    }

    }
