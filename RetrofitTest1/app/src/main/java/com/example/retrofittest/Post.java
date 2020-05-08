package com.example.retrofittest;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

    public class Post {
        @SerializedName("mail")
        private String mail;
        @SerializedName("pass")
        private String pass;
        @SerializedName("phone")
        private String phone;
        @SerializedName("name")
        private String name;
        @SerializedName("id")
        private int id;

        public Post(String mail, String pass, String phone, String name) {
            this.mail = mail;
            this.pass = pass;
            this.phone = phone;
            this.name = name;
        }

        public String getMail() {
            return mail;
        }

        public void setMail(String mail) {
            this.mail = mail;
        }

        public String getPass() {
            return pass;
        }

        public void setPass(String pass) {
            this.pass = pass;
        }

        public String getPhone() {
            return phone;
        }

        public void setPhone(String phone) {
            this.phone = phone;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }
    }
